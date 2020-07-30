import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.concurrent.Executors;
import java.util.HashSet;
import java.util.concurrent.Future;
import java.util.concurrent.ExecutorService;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ESubsequencesEasyVersion solver = new ESubsequencesEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESubsequencesEasyVersion {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);
            int n = in.nextInt();
            long k = in.nextLong();
            BigInt K = new BigInt(k);
            char[] a = StringUtil.toCharArray(in.nextString(), 1);
            BigInt[][] f = new BigInt[n + 1][n + 1];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    f[i][j] = new BigInt(0);
                }
            }
            for (int i = 0; i <= n; i++)
                f[i][0] = new BigInt(1);

            for (int j = 1; j <= n; j++) {
                for (int i = j; i <= n; i++) {
                    f[i][j] = f[i - 1][j - 1].copy();
                }
                for (int i = n; i >= j; i--) {
                    HashSet<Character> used = new HashSet<>();
                    used.add(a[i]);
                    for (int l = i - 1; l >= 1; l--)
                        if (!used.contains(a[l])) {
                            f[i][j].add(f[l][j]);
                            used.add(a[l]);
                        }
                }
            }
//        for (int i = 0; i <= n; i++) {
//            out.println(f[n][i]);
//        }
            int cur = n;
            BigInt ans = new BigInt(0);
            while (!K.isZero()) {
                if (K.compareTo(f[n][cur]) >= 0) {
                    BigInt tmp = new BigInt(n - cur);
                    tmp.mul(f[n][cur]);
                    ans.add(tmp);
                    K.sub(f[n][cur]);
                    cur--;
                    if (cur == -1) break;
                } else {
                    BigInt tmp = new BigInt(n - cur);
                    tmp.mul(K);
                    ans.add(tmp);
                    K = new BigInt(0);
                }
            }
            if (!K.isZero()) out.println(-1);
            else
                out.println(ans);
        }

    }

    static class StringUtil {
        public static char[] toCharArray(String s, int stIndex) {
            char[] result = new char[s.length() + stIndex];
            for (int i = 0; i < s.length(); i++) {
                result[i + stIndex] = s.charAt(i);
            }
            return result;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

    }

    static class BigInt extends Number implements Comparable<BigInt> {
        private static final long mask = (1L << 32) - 1;
        private int sign;
        private int len;
        private int[] dig;

        private BigInt(final int sign, final int[] v, final int len) {
            assign(sign, v, len);
        }

        private BigInt(final int sign, final int val) {
            dig = new int[1];
            uAssign(sign, val);
        }

        private int parse(final char[] s, int from, final int to) {
            int res = s[from] - '0';
            while (++from < to) res = res * 10 + s[from] - '0';
            return res;
        }

        private void mulAdd(final int add) {
            long carry = 0;
            for (int i = 0; i < len; i++) {
                carry = 1000000000 * (dig[i] & mask) + carry;
                dig[i] = (int) carry;
                carry >>>= 32;
            }
            if (carry != 0) dig[len++] = (int) carry;
            carry = (dig[0] & mask) + add;
            dig[0] = (int) carry;
            if ((carry >>> 32) != 0) {
                int i = 1;
                for (; i < len && ++dig[i] == 0; ++i) ;
                if (i == len) dig[len++] = 1; //Todo: reallocate() for general case?
            }
        }

        private void reallocate() {
            final int[] res = new int[dig.length * 2];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        private void reallocate(final int newLen) {
            final int[] res = new int[newLen];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        private void assign(final int[] v, final int vlen) {
            if (vlen > dig.length) dig = new int[vlen + 2];
            System.arraycopy(v, 0, dig, 0, len = vlen);
        }

        private void assign(final int sign, final int[] v, final int len) {
            this.sign = sign;
            this.len = len;
            dig = v;
        }

        private void assign(final String s) {
            assign(s.toCharArray());
        }

        private void assign(final char[] s) {
            sign = s[0] == '-' ? -1 : 1;

            len = s.length + (sign - 1 >> 1);
            final int alloc = len < 10 ? 1 : (int) (len * 3402L >>> 10) + 32 >>> 5; //3402 = bits per digit * 1024
            if (dig == null || alloc > dig.length) dig = new int[alloc];

            int j = len % 9;
            if (j == 0) j = 9;
            j -= (sign - 1 >> 1);

            dig[0] = parse(s, 0 - (sign - 1 >> 1), j);
            for (len = 1; j < s.length; )
                mulAdd(parse(s, j, j += 9));
        }

        private void uAssign(final int s, final int val) {
            sign = s;
            len = 1;
            dig[0] = val;
        }

        private void uAssign(final int s, final long val) {
            sign = s;
            len = 2;
            if (dig.length < 2) reallocate(2);
            dig[0] = (int) (val & mask);
            dig[1] = (int) (val >>> 32);
            if (dig[1] == 0) --len;
        }

        private void assign(final int val) {
            uAssign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        private void assign(final long val) {
            uAssign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        public boolean isZero() {
            return len == 1 && dig[0] == 0;
        }

        private void setToZero() {
            dig[0] = 0;
            len = 1;
            sign = 1; //Remove?
        }

        public int compareAbsTo(final BigInt a) {
            if (len > a.len) return 1;
            if (len < a.len) return -1;
            for (int i = len - 1; i >= 0; i--)
                if (dig[i] != a.dig[i])
                    if ((dig[i] & mask) > (a.dig[i] & mask)) return 1;
                    else return -1;
            return 0;
        }

        public int compareTo(final BigInt a) {
            if (sign < 0) {
                if (a.sign < 0 || a.isZero()) return -compareAbsTo(a);
                return -1;
            }
            if (a.sign > 0 || a.isZero()) return compareAbsTo(a);
            return 1;
        }

        public boolean equals(final BigInt a) {
            if (len != a.len) return false;
            if (isZero() && a.isZero()) return true;
            if ((sign ^ a.sign) < 0) return false; //In case definition of sign would change...
            for (int i = 0; i < len; i++) if (dig[i] != a.dig[i]) return false;
            return true;
        }

        public boolean equals(final Object o) {
            if (o instanceof BigInt) return equals((BigInt) o);
            return false;
        }

        public int hashCode() {
            int hash = 0; //Todo: Opt and improve.
            for (int i = 0; i < len; i++) hash = (int) (31 * hash + (dig[i] & mask));
            return sign * hash; //relies on 0 --> hash==0.
        }

        public byte byteValue() {
            return (byte) (sign * (dig[0] & 0x7F));
        }

        public short shortValue() {
            return (short) (sign * (dig[0] & 0x7FFF));
        }

        public int intValue() {
            return sign * (dig[0] & 0x7FFFFFFF); //relies on that sign always is either 1/-1.
        }

        public long longValue() {
            return len == 1 ? sign * (dig[0] & mask) : sign * ((dig[1] & 0x7FFFFFFFL) << 32 | (dig[0] & mask));
        }

        public float floatValue() {
            final int s = Integer.numberOfLeadingZeros(dig[len - 1]);
            if (len == 1 && s >= 8) return sign * dig[0];

            int bits = dig[len - 1]; //Mask out the 24 MSBits.
            if (s <= 8) bits >>>= 8 - s;
            else bits = bits << s - 8 | dig[len - 2] >>> 32 - (s - 8); //s-8==additional bits we need.
            bits ^= 1L << 23; //The leading bit is implicit, cancel it out.

            final int exp = (int) (((32 - s + 32L * (len - 1)) - 1 + 127) & 0xFF);
            bits |= exp << 23; //Add exponent.
            bits |= sign & (1 << 31); //Add sign-bit.

            return Float.intBitsToFloat(bits);
        }

        public double doubleValue() {
            if (len == 1) return sign * (dig[0] & mask);

            final int s = Integer.numberOfLeadingZeros(dig[len - 1]);
            if (len == 2 && 32 - s + 32 <= 53) return sign * ((long) dig[1] << 32 | (dig[0] & mask));

            long bits = (long) dig[len - 1] << 32 | (dig[len - 2] & mask); //Mask out the 53 MSBits.
            if (s <= 11) bits >>>= 11 - s;
            else bits = bits << s - 11 | dig[len - 3] >>> 32 - (s - 11); //s-11==additional bits we need.
            bits ^= 1L << 52; //The leading bit is implicit, cancel it out.

            final long exp = ((32 - s + 32L * (len - 1)) - 1 + 1023) & 0x7FF;
            bits |= exp << 52; //Add exponent.
            bits |= (long) sign & (1L << 63); //Add sign-bit.

            return Double.longBitsToDouble(bits);
        }

        private void uMul(final int mul) {
            if (mul == 0) {
                setToZero();
                return;
            } //To be oved?

            long carry = 0;
            final long m = mul & mask;
            for (int i = 0; i < len; i++) {
                carry = (dig[i] & mask) * m + carry;
                dig[i] = (int) carry;
                carry >>>= 32;
            }
            if (carry != 0) {
                if (len == dig.length) reallocate();
                dig[len++] = (int) carry;
            }
        }

        private void uMul(final long mul) {
            if (mul == 0) {
                setToZero();
                return;
            }
            if (len + 2 >= dig.length) reallocate(2 * len + 1);

            final long mh = mul >>> 32, ml = mul & mask;
            long carry = 0, next = 0, tmp;
            for (int i = 0; i < len; i++) {
                carry = carry + next; //Could this overflow?
                tmp = (dig[i] & mask) * ml;
                next = (dig[i] & mask) * mh;
                dig[i] = (int) (tmp + carry);
                carry = (tmp >>> 32) + (carry >>> 32) + ((tmp & mask) + (carry & mask) >>> 32);
            }
            carry = carry + next;
            dig[len++] = (int) carry;
            dig[len++] = (int) (carry >>> 32);

            while (len > 1 && dig[len - 1] == 0) --len;
        }

        private void addMag(int[] v, int vlen) {
            int ulen = len;
            int[] u = dig; //ulen <= vlen
            if (vlen < ulen) {
                u = v;
                v = dig;
                ulen = vlen;
                vlen = len;
            }
            if (vlen > dig.length) reallocate(vlen + 1);

            long carry = 0;
            int i = 0;
            for (; i < ulen; i++) {
                carry = (u[i] & mask) + (v[i] & mask) + carry;
                dig[i] = (int) carry;
                carry >>>= 32;
            }
            if (vlen > len) {
                System.arraycopy(v, len, dig, len, vlen - len);
                len = vlen;
            }
            if (carry != 0) //carry==1
            {
                for (; i < len && ++dig[i] == 0; i++) ;
                if (i == len) //vlen==len
                {
                    if (len == dig.length) reallocate();
                    dig[len++] = 1;
                }
            }
        }

        private void subMag(final int[] u, final int ulen) {
            final int vlen = len;
            final int[] v = dig; //ulen <= vlen

            //Assumes vlen=len and v=dig
            long dif = 0;
            int i = 0;
            for (; i < ulen; i++) {
                dif = (v[i] & mask) - (u[i] & mask) + dif;
                dig[i] = (int) dif;
                dif >>= 32;
            }
            if (dif != 0) {
                for (; dig[i] == 0; i++) --dig[i];
                if (--dig[i] == 0 && i + 1 == len) len = ulen;
            }
            while (len > 1 && dig[len - 1] == 0) --len;
        }

        public void add(final BigInt a) {
            if (sign == a.sign) {
                addMag(a.dig, a.len);
                return;
            }
            if (compareAbsTo(a) >= 0) {
                subMag(a.dig, a.len);
                //if(len==1 && dig[0]==0) sign = 1;
                return;
            }

            final int[] v = a.dig;
            final int vlen = a.len;
            if (dig.length < vlen) reallocate(vlen + 1);

            sign = -sign;
            long dif = 0;
            int i = 0;
            for (; i < len; i++) {
                dif = (v[i] & mask) - (dig[i] & mask) + dif;
                dig[i] = (int) dif;
                dif >>= 32;
            }
            if (vlen > len) {
                System.arraycopy(v, len, dig, len, vlen - len);
                len = vlen;
            }
            if (dif != 0) {
                for (; i < vlen && dig[i] == 0; i++) --dig[i];
                if (--dig[i] == 0 && i + 1 == len) --len;
            }
            //if(i==vlen) should be impossible
        }

        public void sub(final BigInt a) {
            if (sign != a.sign) {
                addMag(a.dig, a.len);
                return;
            }
            if (compareAbsTo(a) >= 0) {
                subMag(a.dig, a.len);
                //if(len==1 && dig[0]==0) sign = 1;
                return;
            }

            final int[] v = a.dig;
            final int vlen = a.len;
            if (dig.length < vlen) reallocate(vlen + 1);

            sign = -sign;
            long dif = 0;
            int i = 0;
            for (; i < len; i++) {
                dif = (v[i] & mask) - (dig[i] & mask) + dif;
                dig[i] = (int) dif;
                dif >>= 32;
            }
            if (vlen > len) {
                System.arraycopy(v, len, dig, len, vlen - len);
                len = vlen;
            }
            if (dif != 0) {
                for (; i < vlen && dig[i] == 0; i++) --dig[i];
                if (--dig[i] == 0 && i + 1 == len) --len;
            }
            //if(i==vlen) should be impossible
        }

        public void mul(final BigInt mul) {
            if (isZero()) {
            } else if (mul.isZero()) setToZero();
            else if (mul.len <= 2 || len <= 2) {
                sign *= mul.sign;
                if (mul.len == 1) uMul(mul.dig[0]);
                else if (len == 1) {
                    final int tmp = dig[0];
                    assign(mul.dig, mul.len);
                    uMul(tmp);
                } else if (mul.len == 2) uMul((long) mul.dig[1] << 32 | (mul.dig[0] & mask));
                else {
                    final long tmp = (long) dig[1] << 32 | (dig[0] & mask);
                    assign(mul.dig, mul.len);
                    uMul(tmp);
                }
            } else if (len < 128 || mul.len < 128 || (long) len * mul.len < 1_000_000) smallMul(mul); //Remove overhead?
            else if (Math.max(len, mul.len) < 20000) Karatsuba(mul, false); //Tune thresholds and remove hardcode.
            else Karatsuba(mul, true);
        }

        public void smallMul(final BigInt mul) {
            if (isZero()) return; //Remove?
            if (mul.isZero()) {
                setToZero();
                return;
            }

            sign *= mul.sign;

            int ulen = len, vlen = mul.len;
            int[] u = dig, v = mul.dig; //ulen <= vlen
            if (vlen < ulen) {
                u = v;
                v = dig;
                ulen = vlen;
                vlen = len;
            }

            final int[] res = naiveMul(u, ulen, v, vlen); //Todo remove function overhead.

            dig = res;
            len = res.length;
            if (res[len - 1] == 0) --len;
        }

        private void Karatsuba(final BigInt mul, final boolean parallel) {
            if (mul.dig.length < len) mul.reallocate(len);
            else if (dig.length < mul.len) reallocate(mul.len);

            if (mul.len < len) for (int i = mul.len; i < len; i++) mul.dig[i] = 0;
            if (len < mul.len) for (int i = len; i < mul.len; i++) dig[i] = 0;

            final int mlen = Math.max(len, mul.len);
            int[] res = null;
            if (!parallel) res = kMul(dig, mul.dig, 0, mlen);
            else {
                final ExecutorService pool = Executors.newFixedThreadPool(12);
                try {
                    res = pMul(dig, mul.dig, 0, mlen, 1, pool);
                } catch (Exception e) {
                    System.err.println(e);
                }
                pool.shutdown();
            }

            len = len + mul.len;
            while (res[len - 1] == 0) --len;
            dig = res;
            sign *= mul.sign;
        }

        private static int[] naiveMul(final int[] u, final int ulen, final int[] v, final int vlen) {
            final int[] res = new int[ulen + vlen];
            long carry = 0, tmp, ui = u[0] & mask;
            for (int j = 0; j < vlen; j++) {
                tmp = ui * (v[j] & mask) + carry;
                res[j] = (int) tmp;
                carry = tmp >>> 32;
            }
            res[vlen] = (int) carry;
            for (int i = 1; i < ulen; i++) {
                ui = u[i] & mask;
                carry = 0;
                for (int j = 0; j < vlen; j++) {
                    tmp = ui * (v[j] & mask) + (res[i + j] & mask) + carry;
                    res[i + j] = (int) tmp;
                    carry = tmp >>> 32;
                }
                res[i + vlen] = (int) carry;
            }
            return res;
        }

        private static int[] kMul(final int[] x, final int[] y, final int off, final int n) {
            // x = x1*B^m + x0
            // y = y1*B^m + y0
            // xy = z2*B^2m + z1*B^m + z0
            // z2 = x1*y1, z0 = x0*y0, z1 = (x1+x0)(y1+y0)-z2-z0
            if (n <= 32) {
                final int[] z = new int[2 * n];
                long carry = 0, tmp, xi = x[off] & mask;
                for (int j = 0; j < n; j++) {
                    tmp = xi * (y[off + j] & mask) + carry;
                    z[j] = (int) tmp;
                    carry = tmp >>> 32;
                }
                z[n] = (int) carry;
                for (int i = 1; i < n; i++) {
                    xi = x[off + i] & mask;
                    carry = 0;
                    for (int j = 0; j < n; j++) {
                        tmp = xi * (y[off + j] & mask) + (z[i + j] & mask) + carry;
                        z[i + j] = (int) tmp;
                        carry = tmp >>> 32;
                    }
                    z[i + n] = (int) carry;
                }
                return z;
            }

            final int b = n >>> 1;
            final int[] z2 = kMul(x, y, off + b, n - b);
            final int[] z0 = kMul(x, y, off, b);

            final int[] x2 = new int[n - b + 1], y2 = new int[n - b + 1];
            long carry = 0;
            for (int i = 0; i < b; i++) {
                carry = (x[off + b + i] & mask) + (x[off + i] & mask) + carry;
                x2[i] = (int) carry;
                carry >>>= 32;
            }
            if ((n & 1) != 0) x2[b] = x[off + b + b];
            if (carry != 0) if (++x2[b] == 0) ++x2[b + 1];
            carry = 0;
            for (int i = 0; i < b; i++) {
                carry = (y[off + b + i] & mask) + (y[off + i] & mask) + carry;
                y2[i] = (int) carry;
                carry >>>= 32;
            }
            if ((n & 1) != 0) y2[b] = y[off + b + b];
            if (carry != 0) if (++y2[b] == 0) ++y2[b + 1];

            final int[] z1 = kMul(x2, y2, 0, n - b + (x2[n - b] != 0 || y2[n - b] != 0 ? 1 : 0));

            final int[] z = new int[2 * n];
            System.arraycopy(z0, 0, z, 0, 2 * b); //Add z0
            System.arraycopy(z2, 0, z, b + b, 2 * (n - b)); //Add z2

            //Add z1
            carry = 0;
            int i = 0;
            for (; i < 2 * b; i++) {
                carry = (z[i + b] & mask) + (z1[i] & mask) - (z2[i] & mask) - (z0[i] & mask) + carry;
                z[i + b] = (int) carry;
                carry >>= 32;
            }
            for (; i < 2 * (n - b); i++) {
                carry = (z[i + b] & mask) + (z1[i] & mask) - (z2[i] & mask) + carry;
                z[i + b] = (int) carry;
                carry >>= 32;
            }
            for (; i < z1.length; i++) {
                carry = (z[i + b] & mask) + (z1[i] & mask) + carry;
                z[i + b] = (int) carry;
                carry >>= 32;
            }
            if (carry != 0) while (++z[i + b] == 0) ++i;

            return z;
        }

        private static int[] pMul(final int[] x, final int[] y, final int off, final int n, final int lim, final ExecutorService pool) throws Exception {
            final int b = n >>> 1;

            final Future<int[]> left = pool.submit(() -> lim == 0 ? kMul(x, y, off, b) : pMul(x, y, off, b, lim - 1, pool));

            final Future<int[]> right = pool.submit(() -> lim == 0 ? kMul(x, y, off + b, n - b) : pMul(x, y, off + b, n - b, lim - 1, pool));

            final int[] x2 = new int[n - b + 1], y2 = new int[n - b + 1];
            long carry = 0;
            for (int i = 0; i < b; i++) {
                carry = (x[off + b + i] & mask) + (x[off + i] & mask) + carry;
                x2[i] = (int) carry;
                carry >>>= 32;
            }
            if ((n & 1) != 0) x2[b] = x[off + b + b];
            if (carry != 0) if (++x2[b] == 0) ++x2[b + 1];
            carry = 0;
            for (int i = 0; i < b; i++) {
                carry = (y[off + b + i] & mask) + (y[off + i] & mask) + carry;
                y2[i] = (int) carry;
                carry >>>= 32;
            }
            if ((n & 1) != 0) y2[b] = y[off + b + b];
            if (carry != 0) if (++y2[b] == 0) ++y2[b + 1];

            final Future<int[]> mid = pool.submit(() -> lim == 0 ? kMul(x2, y2, 0, n - b + (x2[n - b] != 0 || y2[n - b] != 0 ? 1 : 0)) :
                    pMul(x2, y2, 0, n - b + (x2[n - b] != 0 || y2[n - b] != 0 ? 1 : 0), lim - 1, pool));

            final int[] z = new int[2 * n];

            final int[] z0 = left.get();
            System.arraycopy(z0, 0, z, 0, 2 * b);
            final int[] z2 = right.get();
            System.arraycopy(z2, 0, z, b + b, 2 * (n - b));

            final int[] z1 = mid.get();

            carry = 0;
            int i = 0;
            for (; i < 2 * b; i++) {
                carry = (z[i + b] & mask) + (z1[i] & mask) - (z2[i] & mask) - (z0[i] & mask) + carry;
                z[i + b] = (int) carry;
                carry >>= 32;
            }
            for (; i < 2 * (n - b); i++) {
                carry = (z[i + b] & mask) + (z1[i] & mask) - (z2[i] & mask) + carry;
                z[i + b] = (int) carry;
                carry >>= 32;
            }
            for (; i < z1.length; i++) {
                carry = (z[i + b] & mask) + (z1[i] & mask) + carry;
                z[i + b] = (int) carry;
                carry >>= 32;
            }
            if (carry != 0) while (++z[i + b] == 0) ++i;
            return z;
        }

        public String toString() {
            if (isZero()) return "0";

            int top = len * 10 + 1;
            final char[] buf = new char[top];
            Arrays.fill(buf, '0');
            final int[] cpy = Arrays.copyOf(dig, len);
            while (true) {
                final int j = top;
                for (long tmp = toStringDiv(); tmp > 0; tmp /= 10)
                    buf[--top] += tmp % 10; //TODO: Optimize.
                if (len == 1 && dig[0] == 0) break;
                else top = j - 13;
            }
            if (sign < 0) buf[--top] = '-';
            System.arraycopy(cpy, 0, dig, 0, len = cpy.length);
            return new String(buf, top, buf.length - top);
        }

        private long toStringDiv() {
            final int pow5 = 1_220_703_125, pow2 = 1 << 13;
            int nextq = 0;
            long rem = 0;
            for (int i = len - 1; i > 0; i--) {
                rem = (rem << 32) + (dig[i] & mask);
                final int q = (int) (rem / pow5);
                rem = rem % pow5;
                dig[i] = nextq | q >>> 13;
                nextq = q << 32 - 13;
            }
            rem = (rem << 32) + (dig[0] & mask);
            final int mod2 = dig[0] & pow2 - 1;
            dig[0] = nextq | (int) (rem / pow5 >>> 13);
            rem = rem % pow5;
            final long pow10 = (long) pow5 * pow2;
            rem = (rem - pow5 * (mod2 - rem) % pow10 * 67) % pow10;
            if (rem < 0) rem += pow10;
            if (dig[len - 1] == 0 && len > 1)
                if (dig[--len - 1] == 0 && len > 1)
                    --len;
            return rem;
        }

        public BigInt(final int val) {
            dig = new int[1];
            assign(val);
        }

        public BigInt(final long val) {
            dig = new int[2];
            assign(val);
        }

        public BigInt(final String s) {
            assign(s);
        }

        public BigInt(final char[] s) {
            assign(s);
        }

        public BigInt copy() {
            return new BigInt(sign, Arrays.copyOf(dig, len), len);
        }

    }
}