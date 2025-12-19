/**
 * @author XGeorge
 * @date 2025/11/9 13:31:29
*/

#include <string_view>

namespace tool {
    /**
     * @brief 根据最后一次出现的分隔符，将字符串切割成两部分。
     * 例如: "aa.bb.cc" -> ["aa.bb", "cc"]
     * @param str 要切割的字符串视图。
     * @param delimiter 分隔符。
     * @return 一个包含两部分字符串视图的 std::pair。第一部分是分隔符前的所有内容，第二部分是分隔符后的内容。
     */
    std::pair<std::string_view, std::string_view> splitAtLast(const std::string_view &str, char delimiter = '.');
};


