/* given a string containing only opening and closing brackets 
write a function to print the in following order
[start position, close position, [nested]]
{}{{}} = [[0,1,nil]],[[2,5, [[3,4,nil]]]]
*/

// stack -> { ->  {0, 0}
// } ->  { 1, 1} -> { 0, 1, nil}

stack-> {}
< 0, 2>
< 0, 3>
<1, 4> - > { 3, 4, 0}
< 1, 5> -> [ 2, 5, 1]



