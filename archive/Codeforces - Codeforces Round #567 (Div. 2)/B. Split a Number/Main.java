import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
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
        BSplitANumber solver = new BSplitANumber();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSplitANumber {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            String s = in.nextString();
            int mid = n / 2;

            BigInt res1 = new BigInt(0);
            BigInt res2 = new BigInt(0);
            for (int i = mid + 1; i < s.length(); i++) {
                if (s.charAt(i) != '0') {
                    BigInt first = new BigInt(s.substring(0, i));
                    first.add(new BigInt(s.substring(i)));
                    res1 = first;
                    break;
                }
            }
            for (int i = mid; i > 0; i--) {
                if (s.charAt(i) != '0') {
                    BigInt first = new BigInt(s.substring(0, i));
                    first.add(new BigInt(s.substring(i)));
                    res2 = first;
                    break;
                }
            }
            if (res1.isZero()) out.println(res2);
            else {
                if (!res2.isZero() && res1.compareTo(res2) > 0)
                    out.println(res2);
                else out.println(res1);
            }
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

    }
}