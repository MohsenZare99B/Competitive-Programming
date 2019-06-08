import java.util.*;
import java.util.stream.*;

public class MyString {
    static Boolean trueBool, falseBool;

    public static void main(String[] args) {
        String string = "STRING";
        trueBool = "string".equalsIgnoreCase(string);

        switch (string.toLowerCase()) {
            case "string":
                System.out.println("lower");
                break;
            case "STR":
                System.out.println("upper");
                break;
        }

        char[] chars = string.toCharArray();
        chars[0] = 's';

        string = String.valueOf(chars);

        trueBool = string.toLowerCase().contains("str");

        String a = "alpha", b = "alpha";
        String c = new String(/*original:*/"alpha");

        trueBool = (a == b && b.equals(c));
        falseBool = (a == c || b == c);

        a = "a b c d";
        String[] elements = a.split(/*regex:*/" ");

        b = "a b     c       d ";
        elements = b.split(/*regex:*/"\\s+");

        c = String.join(/*delimiter:*/"+", elements);

        StringJoiner sj = new StringJoiner(/*delimiter:*/"/", /*prefix:*/"<", /*suffix:*/">");
        sj.add("a");
        sj.add("b");
        a = sj.toString();

        b = Stream.of(elements).collect(Collectors.joining(/*delimiter:*/" , ", /*prefix:*/ "[", /*suffix:*/ "] "));

        StringBuilder stringBuilder = new StringBuilder("sb... : ");
        a = stringBuilder.append(a).append(b).append(c).toString();

        c = a.concat(b);
        c = a + b;

        c = c.substring(0, 3);

        c = stringBuilder.reverse().toString();

        c = "    \n  " + c + "    \n       ";
        c = c.trim();

        c = c.replace(/*target:*/"a", /*replacement:*/"xxx");

        Formatter formatter = new Formatter();
        formatter.format("One:%d, String:%s", 1, b);
        System.out.println(formatter);

        System.out.println(stringBuilder.charAt(stringBuilder.length() - 1) + "\n");
        
        StringTokenizer tokenizer = new StringTokenizer(/*str:*/"a*b*c*d", "*");
        while (tokenizer.hasMoreTokens()) {
            System.out.println(tokenizer.nextToken());
        }
    }
}
