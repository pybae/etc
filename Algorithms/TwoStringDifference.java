public class TwoStringDifference {

    public static void main(String[] args) {
        System.out.println(foo("cat", "cast"));
        System.out.println(foo("cat", "cats"));
        System.out.println(foo("cat", "dog"));
        System.out.println(foo("cat", "casts"));
    }

    public static boolean foo(String s1, String s2) {
        String sShort =  s1.length() < s2.length() ? s1 : s2;
        String sLong = s1.length() >= s2.length() ? s1: s2;
        int si = 0;
        int li = 0;
        Boolean changed = false;
        int diff = 0;

        for (int i = 0; i < sShort.length(); i++) {
            if (sShort.charAt(i) != sLong.charAt(i)) {
                if (changed)
                    return false;
                changed = true;
            }
        }

        return true;
    }
}
