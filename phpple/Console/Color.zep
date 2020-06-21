namespace Phpple\Console;

class Color
{
    // colors of string
    private static colors = [
        "black": "0;30",
        "dark_gray": "1;30",
        "blue": "0;34",
        "light_blue": "1;34",
        "green": "0;32",
        "light_green": "1;32",
        "cyan": "0;36",
        "light_cyan": "1;36",
        "red": "0;31",
        "light_red": "1;31",
        "purple": "0;35",
        "light_purple": "1;35",
        "brown": "0;33",
        "yellow": "1;33",
        "light_gray": "0;37",
        "white": "1;37"
    ];
    // background color of string
    private static bgColors = [
        "black": "40",
        "red": "41",
        "green": "42",
        "yellow": "43",
        "blue": "44",
        "magenta": "45",
        "cyan": "46",
        "light_gray": "47"
    ];

    /**
     * Get colored string
     * @param string original string
     * @param string color the color of the $str
     * @param string backColor the background color or the $str
     * @return string
     */
    public static function getColoredString(string $str, string! $color = null, string! $backColor = null) -> string
    {
        string result = "";
        if color != null && isset self::colors[color] {
            let result .=  "\033[" . self::colors[color] . "m";
        }

        if backColor != null && isset self::bgColors[backColor] {
            let result .= "\033[" . self::bgColors[backColor] . "m";
        }

        let result .= str;

        if color != null || backColor != null {
            let result .= "\033[0m";
        }
        return result;
    }

    /**
     * Output normal information
     * @param string content content of information
     * @return string
     */
    public static function info(string content)
    {
        fwrite(STDOUT, self::getColoredString(content, "light_gray"). PHP_EOL);
    }

    /**
     * Output warning information
     * @param string content content of information
     * @return string
     */
    public static function warn(string content)
    {
        fwrite(STDOUT, self::getColoredString(content, "yellow"). PHP_EOL);
    }

    /**
     * Output success information
     * @param string content content of information
     * @return string
     */
    public static function success(string content)
    {
        fwrite(STDOUT, self::getColoredString(content, "green"). PHP_EOL);
    }

    /**
     * Output error information
     * @param string content content of information
     * @return string
     */
    public static function error(string content)
    {
        fwrite(STDERR, self::getColoredString(content, "red"). PHP_EOL);
    }
}
