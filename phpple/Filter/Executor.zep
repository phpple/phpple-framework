namespace Phpple\Filter;

use Phpple\Application;
use Phpple\Log\LoggerInterface;

class Executor
{
    /**
     * @var FilterInterface[]
     */
    private impFilters = [];
    /**
     * @var Application
     */
    private app = null;

    /**
     * @var <LoggerInterface>
     */
    private logger;

    /**
     * Executor constructor.
     *
     * @param Application $app
     */
    public function __construct(<Application> app)
    {
        let this->app = app;
        let this->logger = this->app->getLogger();
    }

    /**
     * Load filters
     *
     * @param filters
     *
     * @throws Exception
     */
    public function loadFilters(array filters)
    {
        var key, classes;
        for key, classes in filters {
            var classname, cls;
            for _, classname in classes {
                //Logger::debug('load filter %s.%s',$key,$classname);
                let cls = new {classname}();
                if !(cls instanceof FilterInterface) {
                    throw new Exception("phpple.errFilterInstance");
                }
                let this->impFilters[key][] = cls;
            }
        }
    }

    /**
     * Execute filter
     *
     * @param filtername
     *
     * @return bool
     */
    public function execute(string filterName) -> boolean
    {
        if !isset this->impFilters[filterName] {
            return true;
        }
        string key = "f_".filterName;
        this->app->getTimer()->begin(key);
        var filters = this->impFilters[filterName], filter;
        for _, filter in filters {
            if filter->execute(this->app) === false {
                this->logger->info(sprintf("call filter %s.%s=false", filterName, get_class(filter)));
                this->app->timer->end("f_" . filterName);
                return false;
            }
        }
        this->app->getTimer()->end(key);
        return true;
    }
}
