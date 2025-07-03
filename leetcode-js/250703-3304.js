// 3304. 找出第 K 个字符 I

// 提示
// Alice 和 Bob 正在玩一个游戏。最初，Alice 有一个字符串 word = "a"。

// 给定一个正整数 k。

// 现在 Bob 会要求 Alice 执行以下操作 无限次 :

// 将 word 中的每个字符 更改 为英文字母表中的 下一个 字符来生成一个新字符串，并将其 追加 到原始的 word。
// 例如，对 "c" 进行操作生成 "cd"，对 "zb" 进行操作生成 "zbac"。

// 在执行足够多的操作后， word 中 至少 存在 k 个字符，此时返回 word 中第 k 个字符的值。

// 注意，在操作中字符 'z' 可以变成 'a'。

 /**
 * @param {number} k
 * @return {character}
 */
var kthCharacter = function(k) {
    let word = "a";
    while(word.length <= k){
        let result = "";
        for(let letter of word){
            result += String.fromCharCode(asciiCodeletter.charCodeAt(0) + 1);
        }
        word = word + result;
        console.log(word);
    }
};