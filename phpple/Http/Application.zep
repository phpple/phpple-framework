namespace Phpple\Http;

use Phpple\Application as BaseApplication;
use Phpple\Filter\Executor;
use Phpple\Util\Conf;

class Application extends BaseApplication
{
    /**
     * @var Executor
     */
    private filterExecutor;

    /**
     * baseUrl
     * @var string
     */
    private baseUrl;
    
    protected function init()
    {
        let this->request = new Request(this);
        let this->response = new Response(this);

        this->initEnv();
        this->initLogger();

        this->request->setLogger(this->logger);
        this->response->setLogger(this->logger);

        let this->filterExecutor = new Executor(this);
        this->initFilters();
    }

    /**
     * @inheritDoc
     */
    protected function process()
    {
        var filter;
        for filter in [
                     self::FILTER_INIT,
                     self::FILTER_INPUT,
                     self::FILTER_ROUTE,
                     self::FILTER_OUTPUT
                 ] {
            if false === this->execFilter(filter) {
                break;
            }
        }
    }

    /**
     * Initialize filters
     */
    private function initFilters()
    {
        var filters = [];
        let filters[self::FILTER_INIT] = this->getFilter(
            "phpple.filter." . self::FILTER_INIT,
            []
        );
        let filters[self::FILTER_INPUT] = this->getFilter(
            "phpple.filter." . self::FILTER_INPUT,
            ["\\Phpple\\Filter\\InputFilter"]
        );
        let filters[self::FILTER_ROUTE] = this->getFilter(
            "phpple.filter." . self::FILTER_ROUTE,
            ["\\Phpple\\Filter\\RouteFilter"],
            true
        );
        let filters[self::FILTER_OUTPUT] = this->getFilter(
            "phpple.filter." . self::FILTER_OUTPUT,
            ["\\Phpple\\Filter\\OutputFilter"]
        );
        let filters[self::FILTER_CLEAN] = this->getFilter(
            "phpple.filter." . self::FILTER_CLEAN,
            []
        );

        this->filterExecutor->loadFilters(filters);
    }

    /**
     * Fetch filter
     *
     * @param string name
     * @param array defaults
     * @param boolean cover
     *
     * @return array
     */
    private function getFilter(string name, array defaults, boolean cover = false) -> array
    {
        var filters = Conf::get(name, []);
        if is_string(filters) {
            let filters = [
                filters
            ];
        }
        if !cover {
            let defaults = array_diff(defaults, filters);
            return array_merge(defaults, filters);
        }
        if filters {
            return filters;
        }
        return defaults;
    }

    /**
     * Execute filter
     */
    public function execFilter(string filterName) -> boolean
    {
        return this->filterExecutor->execute(filterName);
    }
}