import java.util.*;
import java.util.stream.*;

public class MySet {
    public static void main(String[] args) {
        Set<Integer> hashSet = new HashSet<>();
        Set<Integer> linkedHashSet = new LinkedHashSet<>();
        Set<Integer> sortedSet = new TreeSet<>();

        sortedSet.add(12);
        sortedSet.add(3);

        ArrayList<Integer> list = new ArrayList<>();
        list.addAll(sortedSet);

        sortedSet.remove(/*o:*/12);

        Boolean trueBool = hashSet.isEmpty();
        Boolean falseBool = hashSet.contains(433);

        sortedSet.clear();
        int sz = sortedSet.size();

        linkedHashSet.addAll(list);
        linkedHashSet.add(-912);
        linkedHashSet.add(4324);
        linkedHashSet.add(3);

        System.out.println(linkedHashSet);

        Set<String> h = new HashSet<String>() {{
            add("a");
            add("b");
        }};
        Set<String> stringSet = Stream.of("a", "b", "c").collect(Collectors.toSet());
    }
}