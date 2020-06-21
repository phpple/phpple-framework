<?php
namespace App\Controller\Foo;
use Phpple\Http\Request;
use Phpple\Http\Response;

/**
 *
 * @author: ronnie
 * @since: 2020/6/21 8:44 上午
 * @copyright: 2020@100tal.com
 * @filesource: Controller.php
 */
class Controller extends \Phpple\Http\Controller
{
    public function bar(Request $req, string $a = 'hello')
    {
        $this->logger->notice("request:".$req->getRawUri());
        $this->set('foo', $a)
            ->set('url', $req->getUrl())
            ->sets([
                'a' => 'b',
                'method' => $req->getMethod(),
            ])
        ;
    }
}
