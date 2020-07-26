package Code;

import java.util.ArrayList;

@SuppressWarnings("unused")
public class IdealString {
    public String construct(int length) {
        int[] min = new int[20];
        int[] max = new int[20];
        for (int i = 1; i <= 18; i++) {
            min[i] = i;
            max[i] = (1 << (i - 1));
        }
        int sumMin = 0;
        int sumMax = 0;
        int p = -1;
        for (int i = 1; i <= 18; i++) {
            sumMax += max[i];
            sumMin += min[i];
            if (sumMin <= length && length <= sumMax) {
                p = i;
                break;
            }
        }
        if (p == -1)
            return "";
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 1; i <= p; i++) list.add(i);
        int cur = sumMin;
        while (cur < length) {
            boolean d = false;
            for (int i = 0; i < list.size() - 1; i++) {
                if (list.get(i) < max[i + 1] && list.get(i) < list.get(i + 1) - 1) {
                    d = true;
                    list.set(i, list.get(i) + 1);
                    break;
                }
            }
            if (!d) list.set(list.size() - 1, list.get(list.size() - 1) + 1);
            cur++;
        }
        ArrayList<Character> charList = new ArrayList<>();

        char c = 'A';
        for (int i : list) {
            for (int j = 1; j < i; j++) charList.add(c);
            c++;
        }
        p = 0;
        c = 'A';
        int pc = 0;

        StringBuilder ans = new StringBuilder();
        for (int i = 1; i <= length; i++) {
            if (p < list.size() && i == list.get(p)) {
                ans.append(c++);
                p++;
            } else if (pc < charList.size())
                ans.append(charList.get(pc++));
        }

        return ans.toString();
    }
}
