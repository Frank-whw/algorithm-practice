// 1456. 定长子串中元音的最大数目

// 相关企业
// 提示
// 给你字符串 s 和整数 k 。

// 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。

// 英文中的 元音字母 为（a, e, i, o, u）。

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */

// var has = function(s, i) {
//     if(s[i] == 'a' ||
//             s[i] == 'e' ||
//             s[i] == 'i' ||
//             s[i] == 'o' ||
//             s[i] == 'u'
//         ){
//             return true;
//         }
//         return false;
// }

// 判断字符是否为元音的辅助函数
var has = function(s, i) {
    return ['a', 'e', 'i', 'o', 'u'].includes(s[i]);
};

var maxVowels = function(s, k) {
    let result = 0, cur = 0;
    for(let i = 0; i < k;i++){
        if(has(s, i)){
            cur += 1;
        }
    }
    result = cur;
    for(let left = 0; left + k < s.length; left++){
        if(has(s,left)){
            cur -=1;
        }
        if(has(s, left + k)){
            cur += 1;
        }
         // 更新最大值
        result = Math.max(result, cur);
    }
    return result;
};