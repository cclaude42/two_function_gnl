# Two Function GNL

This is my little attempt and writing a short GNL, without sacrificing readability or efficiency.

### With clean code, please!

The program is fully protected against errors, including malloc fails and bad reads.
As far as I know, it works with everything.

The program is fully normed (if you remove the comments, of course).
This includes the 2020 rules, so **no ternaries**.

It doesn't use any tricks, like doing stuff in conditions, setting variables to -1 with a ++i, or any other crime against humanity (as far as I know).
The only thing I do to get less lines is passing ``i`` and ``j`` to ``join_buffer`` as 0, so I don't have to declare them.

It's crazy how much you can do with so little code, isn't it ?
