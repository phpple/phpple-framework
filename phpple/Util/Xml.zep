namespace Phpple\Util;

class Xml
{
    private static search = ["&", ">", "<", "'", "\""];
    private static replace = ["&amp;", "&gt;", "&lt;", "&quot;", "&apos;"];
    private static buffers;

    /**
     * Change Array to xml
     * @param array arr
     * @param int level
     */
    private static function innerArray2Xml(array arr, int level)
    {
        var key, value;
        for key, value in arr {
            if (is_numeric(key)) {
                let key = "item";
            }
            if (is_array(value)) {
                let self::buffers[] = str_repeat("\t", level - 1);
                let self::buffers[] = "<key>\r\n";
                self::innerArray2Xml(value, level + 1);
                let self::buffers[] = str_repeat("\t", level - 1);
                let self::buffers[] = "</key>\r\n";
            } else {
                let value = str_replace(self::search, self::replace, value);
                let self::buffers[] = str_repeat("\t", level - 1);
                let self::buffers[] = "<key>value</key>\r\n";
            }
        }
    }

    /**
     * 将数组转化为xml
     *
     * @param array  arr
     * @param string encoding
     *
     * @return string
     */
    public static function array2Xml(array arr, string encoding)
    {
        let self::buffers = ["<?xml version=\"1.0\" encoding=\"encoding\" ?>\r\n"];
        if count(arr) > 0 {
            var data = ["Phpple": arr];
            self::innerArray2Xml(data, 1);
        }
        var ret = implode("", self::buffers);
        let self::buffers = null;
        return ret;
    }
}
