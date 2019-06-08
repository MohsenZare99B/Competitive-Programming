import java.util.*;
import java.util.stream.*;

public class MyMap {
    static Boolean trueBool, falseBool;
    static Integer a, b;

    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();

        map.put("a", 1);
        map.put("b", 2);

        a = map.get("a");

        falseBool = map.containsKey("c");
        trueBool = map.containsValue(1);

        map.putIfAbsent("c", 3);

        map.remove("c", 1);
        trueBool = map.containsKey("c");
        map.remove(/*key:*/"c");
        falseBool = map.containsKey("c");

        a = map.getOrDefault(/*key:*/"c", /*defaultValue:*/3000);
        System.out.println(a);

        map.replaceAll((k, v) -> v + 10);
        map.forEach((k, v) -> System.out.println("Key: " + k + " :: Value: " + v));

        map.replace("a", 32);

        map.computeIfAbsent(/*key:*/"Mohsen", k -> map.get("a") + 10);
        map.computeIfPresent(/*key:*/"a", (k, v) -> v + 10);
        map.compute(/*key:*/"Zare", (k, v) -> 50);

        for (String key : map.keySet())
            System.out.print(key + " ");
        for (Integer value : map.values())
            System.out.print(value + " ");
        for (Map.Entry<String, Integer> entry : map.entrySet())
            System.out.printf("\nKey is %s, Value is %d", entry.getKey(), entry.getValue());

        map.clear();
        System.out.println("\n" + map.size());

        Map<String, String> map2 = Arrays.stream(new String[][]{
                {"a", "A"},
                {"b", "B"}
        }).collect(Collectors.toMap(m -> m[0], m -> m[1]));

        Map<String, String> map3 = new HashMap<>();
        map3.putAll(map2);
        System.out.println(map3);
    }


    class MyKey {
        private String name;

        MyKey(String name) {
            this.name = name;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof MyKey) {
                return this.name.equals(((MyKey) obj).name);
            }
            return false;
        }


        public int hashCode() {
            return this.name.hashCode();
        }
    }
}
