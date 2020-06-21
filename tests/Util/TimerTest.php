<?php
/**
 *
 * @author: ronnie
 * @since: 2020/6/20 2:02 下午
 * @copyright: 2020@100tal.com
 * @filesource: TimerTest.php
 */

namespace Phpple\Tests\Util;

use PHPUnit\Framework\TestCase;

class TimerTest extends TestCase
{
    public function testTimer()
    {
        $timer = new \Phpple\Util\Timer();
        $timer->begin('hello');
        for($i = 0; $i < 10; $i++) {
            usleep(10000);
        }
        $timer->end('hello');

        var_dump($timer->getResult());
    }
}
