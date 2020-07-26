package Code;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

@SuppressWarnings("unused")
public class CutSticks {
    public double maxKth(int[] sticks, int C, int K) {
        double esp = 1e-9;
        double l = 1e-9;
        double r = 1e9;
        ArrayList<Double> list = new ArrayList<>();
        list.add(2e9);
        for (int i : sticks) list.add((double) i);
        int n = list.size() - 1;
        list.sort(Collections.reverseOrder());
        int it = 1000;
        while (it-- > 0) {
            double m = (l + r) / 2.0;
//        double m = 1.0;
            long num = 0;
            int c = C;

            for (int i = 1; i <= n; i++) {
                if (list.get(i).compareTo(m) >= 0) {
                    num++;
                    if (c != 0) {
                        int add = Math.min(c, (int) (Math.floor(list.get(i) / m)) - 1);
                        num += add;
                        c -= add;
                    }
                } else break;
            }
//        System.out.println(num);
//        if (num >= K) System.out.println("!!!");

            if (num >= K) l = m;
            else r = m;
        }
        return l;
    }
}
