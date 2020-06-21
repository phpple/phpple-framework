namespace Phpple\Util;

/**
 * Configure
 */
class Conf
{
    private static loadedFiles = [];
    private static confData = [];

    /**
     * Load the configure files
     *
     * @param string|array paths
     */
    public static function load(paths)
    {
        if !is_array(paths) {
            let paths = [paths];
        }
        var path;
        for _, path in paths {
            if isset self::loadedFiles[path] {
                continue;
            }
            if is_readable(path) {
                require path;
                let self::loadedFiles[path] = true;
            }
        }
    }

    /**
     * Get the configure data by key
     *
     * @param string key
     * @param mixed  default
     *
     * @return mixed|null
     */
    public static function get(string key, defval = null) -> var
    {
        if array_key_exists(key, self::confData) {
            return self::confData[key];
        }
        return defval;
    }

    /**
     * Set the configure data by key
     *
     * @param string key key of the configure
     * @param mixed  value
     */
    public static function set(string key, value)
    {
        let self::confData[key] = value;
    }

    /**
     * Check if the key is defined
     *
     * @param string key
     *
     * @return bool
     */
    public static function has(string key) -> boolean
    {
        return array_key_exists(key, self::confData);
    }

    /**
     * Clear the configure data
     */
    public static function clear()
    {
        let self::loadedFiles = [];
        let self::confData = [];
    }
}
