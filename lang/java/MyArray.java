import java.util.*;
import java.util.stream.*;

public class MyArray {
    static Boolean trueBool, falseBool;

    static int[] makeArray() {
        int[] arr = {10, 20, 30, 40, 50};
        return arr;
    }

    public static void main(String args[]) {
        int[] myArray = makeArray();
        Arrays.setAll(myArray, i -> i * i);
        for (int i : myArray)
            System.out.print(i + " "); // 0 1 4 9 16
        System.out.println();

        String[] strings = {"a", "b", "c"};
        List<String> stringList = Arrays.asList(strings);

        ArrayList<String> list = new ArrayList<>();
        list.addAll(Arrays.asList(strings));

        Set<String> set = new HashSet<>();
        set.add("blue");
        String[] stringArray = set.toArray(new String[set.size()]);

        String[][] stringMatrix = new String[2][];
        stringMatrix[0] = new String[3];
        stringMatrix[1] = new String[14];

        String[][][] stringMatrix2 = new String[10][10][10];

        int[][] intMatrix = {
                {1, 2, 3},
                null,
                {1, 2, 3, 4, 5, 6, 7},
                {1}
        };

        System.out.println(Arrays.toString(myArray));
        System.out.println(Arrays.deepToString(intMatrix)); 
        // Arrays.toString() doesn't work for matrices

        String[] string2 = {"Mohsen", "Zare", "ACM", "Mohsen"};
        int index = IntStream.range(0, string2.length)
                .filter(i -> "Mohsen".equals(string2[i]))
                .findFirst()
                .orElse(-1);

        int index2 = Arrays.asList(string2).indexOf("Zare");


        Arrays.sort(string2);
        int index3 = Arrays.binarySearch(string2, "ACM");

        Arrays.sort(string2, /*from index */0, string2.length, Collections.reverseOrder());
        falseBool = Arrays.asList(string2).contains("KNTU");

        String[] string3 = Arrays.copyOf(string2, string2.length + 1);
        string3[string2.length] = "KNTU";

        String[] string4 = string3.clone();
        falseBool = Arrays.equals(string3, string4);
        trueBool = Arrays.deepEquals(string3, string4);

    }
}