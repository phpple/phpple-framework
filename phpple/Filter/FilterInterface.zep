namespace Phpple\Filter;

use Phpple\Application;

/**
 * Filter interface
 */
interface FilterInterface
{
    /**
     * Execute filter
     *
     * @param Application app
     *
     * @return bool
     */
    public function execute(<Application> app) -> boolean;
}
