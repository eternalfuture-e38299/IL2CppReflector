/**
 * @author XGeorge
 * @date 2025/11/9 13:31:29
*/

#include "IL2CppReflector/tool.h"

namespace tool {
    std::pair<std::string_view, std::string_view> splitAtLast(const std::string_view &str, char delimiter) {
        auto last_dot = str.rfind(delimiter);
        if (last_dot != std::string_view::npos) {
            // 找到了分隔符
            return {
                    str.substr(0, last_dot),               // 分隔符之前的部分
                    str.substr(last_dot + 1)             // 分隔符之后的部分
            };
        }
        // 未找到分隔符，返回一个空的前半部分和完整的原始字符串
        return {"", str};
    }
};