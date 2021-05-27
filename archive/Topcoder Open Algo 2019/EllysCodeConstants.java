package Code;

@SuppressWarnings("unused")
public class EllysCodeConstants {
    public String getLiteral(String candidate) {
        char[] a = candidate.toCharArray();
        int num = 0;
        if (candidate.endsWith("ULL") || candidate.endsWith("LLU")) num = 3;
        else if ((candidate.endsWith("LL") || candidate.endsWith("UL")) || candidate.endsWith("LU")) num = 2;
        else if (candidate.endsWith("L") || candidate.endsWith("U")) num = 1;

        System.out.println(num);
        if (a.length - num == 0) return "";
        for (int i = 0; i < a.length - num; i++) {
            if (a[i] <= 'F' && a[i] >= 'A') continue;
            if (Character.isDigit(a[i])) continue;
            if (a[i] == 'O') a[i] = '0';
            else if (a[i] == 'I') a[i] = '1';
            else if (a[i] == 'Z') a[i] = '2';
            else if (a[i] == 'S') a[i] = '5';
            else if (a[i] == 'T') a[i] = '7';
            else return "";
        }
        StringBuilder s = new StringBuilder("0x");
        for (char c : a) s.append(c);
        return s.toString();
    }
}
