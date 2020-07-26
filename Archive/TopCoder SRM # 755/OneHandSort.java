package Code;

import java.util.ArrayList;
import java.util.Arrays;

public class OneHandSort {
    public int[] sortShelf(int[] target) {
        ArrayList<Integer> ans = new ArrayList<>();
        int n = target.length;
        int[] a = new int[n + 2];
        int[] b = new int[n + 2];

        System.arraycopy(target, 0, a, 0, n);
        System.arraycopy(target, 0, b, 0, n);
        Arrays.sort(b, 0, n);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        a[n] = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (a[i] != -1) {
                    ans.add(i);
                    for (int j = i + 1; j <= n; j++) {
                        if (a[j] == -1) {
                            a[j] = a[i];
                            break;
                        }
                    }
                    a[i] = -1;
                }
                for (int j = i + 1; j <= n; j++)
                    if (a[j] == b[i]) {
                        a[j] = -1;
                        a[i] = a[j];
                        ans.add(j);
                        break;
                    }
            }
        }
        int[] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }
        return res;
    }
}
