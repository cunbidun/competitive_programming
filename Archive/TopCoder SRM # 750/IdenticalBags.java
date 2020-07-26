package Code;

public class IdenticalBags {
    public long makeBags(long[] candy, long bagSize) {
        long l = 0, r = (long) 1e18;
        while (l != r) {
            if (l == r - 1) {
                if (ch(candy, r, bagSize)) return r;
                return l;
            }
            long m = (l + r) >> 1;
            if (ch(candy, m, bagSize)) l = m;
            else r = m - 1;
        }
        return l;
    }

    private boolean ch(long candy[], long m, long bagSize) {
        long cur = 0;
        for (int i = 0; i < candy.length; i++) {
            cur += candy[i]/m;
        }
        return cur >= bagSize;
    }
}
