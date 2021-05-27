package Code;

@SuppressWarnings("unused")
public class EllysAndXor {
    public int getMax(int[] numbers) {
        int n = numbers.length;
        int ans = 0;
        for (int i = 0; i < (1 << (n - 1)); i++) {
            int cur = numbers[0];
            for (int j = 0; j <= n - 2; j++) {
                if (((i >> j) & 1) == 1) {
                    cur ^= numbers[j + 1];
                } else {
                    cur &= numbers[j + 1];
                }
            }

            ans = Math.max(ans, cur);
        }
        return ans;
    }
}
