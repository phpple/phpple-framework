namespace Phpple\Filter;

use Phpple\Application;
use Phpple\Log\LoggerInterface;

class OutputFilter implements FilterInterface
{
    private logger { set, get };

    /**
     * @inheritDoc
     */
    public function execute(<Application> app) -> boolean
    {
        app->getResponse()->send();
        return true;
    }
}
