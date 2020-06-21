namespace Phpple\Filter;

use Phpple\Application;
use Phpple\Log\LoggerInterface;

class CleanFilter implements FilterInterface
{
    private logger { set, get };

    public function __construct()
    {
    }

    /**
     * @inheritDoc
     */
    public function execute(<Application> app) -> boolean
    {
        return true;
    }
}
