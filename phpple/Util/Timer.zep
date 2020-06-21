namespace Phpple\Util;

class Timer
{
    private start = 0;
    private stats = [];

    /**
     * Timer constructor
     */
    public function __construct()
    {
        let this->start = microtime(true);
    }

    /**
     * Begin a timer segment.The last timer will be terminated
     *
     * @param string[] $phases the name of the timers
     *
     * @return float current timestamp(unit:10^-3ms)
     */
    public function begin() -> int
    {
        var now = microtime(true), phase;
        for _, phase in func_get_args() {
            if !isset this->stats[phase] {
                let this->stats[phase] = [now, 0];
            }
        }
        return now;
    }

    /**
     * Terminate the timers
     *
     * @param string[] $phases the names of timer that will be terminated
     *
     * @return float current timestamp
     */
    public function end() -> int
    {
        var now = microtime(true), phase;
        for _, phase in func_get_args() {
            if isset this->stats[phase] {
                let this->stats[phase][1] = now;
            }
        }
        return now;
    }

    /**
     * Terminate all timers
     *
     * @return float current timestamp
     */
    public function endAll() -> int
    {
        var now = microtime(true), phase, stat;
        for phase, stat in this->stats {
            if stat[1] === 0 {
                let this->stats[phase][1] = now;
            }
        }
        return now;
    }

    /**
     * Get the result of all timers
     *
     * @param bool $end if stop all timers
     *
     * @return array array(
     *  $phase => $cost
     * )
     */
    public function getResult(boolean end = true) -> array
    {
        if end {
            this->endAll();
        }
        array result = [];
        var phase, stat;
        for phase, stat in this->stats {
            if stat[1] {
                let result[phase] = intval(($stat[1] - $stat[0]) * 1000000);
            }
        }
        return result;
    }
}
