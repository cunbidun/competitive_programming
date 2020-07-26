package Code;

@SuppressWarnings("unused")
public class OneHandRoadPainting {
    public long fastest(int[] dStart, int[] dEnd, int paintPerBrush) {
        int n = dStart.length;
        long ans = 0;
        long extra = 0;
        for (int i = n - 1; i >= 0; i--) {
            long finish = dEnd[i];
            long len = dEnd[i] - dStart[i];
            if (extra > len) {
                extra -= len;
                continue;
            }
            len -= extra;
            finish -= extra;
            long cnt = (len + (long) paintPerBrush - 1) / (long) paintPerBrush;
            long last = finish - (cnt - 1) * paintPerBrush;
            ans += (finish + last) * cnt;
            System.out.println("ans: " + ans);
            extra = paintPerBrush - (last - dStart[i]);
        }
        return ans;
    }
}
