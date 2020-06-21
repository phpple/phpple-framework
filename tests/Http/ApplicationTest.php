<?php
/**
 *
 * @author: ronnie
 * @since: 2020/6/20 3:38 下午
 * @copyright: 2020@100tal.com
 * @filesource: ApplicationTest.php
 */

namespace Phpple\Tests\Http;

use App\Controller\Foo\Controller;
use Phpple\Filter\RouteFilter;
use Phpple\Helper\RequestBuilder;
use Phpple\Http\Application;
use Phpple\Http\Request;
use PHPUnit\Framework\TestCase;

class ApplicationTest extends TestCase
{
    public function testApplication()
    {
        RequestBuilder::buildGetRequest("/foo/bar?a=b&_pretty=1&_of=json");

        $root = dirname(__DIR__)."/site/";
        $app = new Application($root );
        $app->run();

//        $req = new Request();
//        $req->setUrl("/foo/bar");
//
//        $app->setRequest($req);
//
//        $filter = new RouteFilter();
//        $filter->execute($app);

        $file = $root.'/log/logger-'.date('Y-m-d').'.log';
        $this->assertTrue(is_file($file));
    }

    public function testReflectionClass()
    {
        require_once dirname(__DIR__).'/site/App/Controller/Foo/Controller.php';
        $refClass = new \ReflectionClass(Controller::class);
        $req = new Request();
        foreach($refClass->getMethod("bar")->getParameters() as $param) {
            $cls = $param->getClass();
            var_dump($param->getName());
            var_dump($cls === NULL);
            var_dump($cls->getName() == Request::class);
            if ($param->getName() == 'req') {
                $this->assertTrue($cls->isInstance($req));
            }
        }
    }
}
