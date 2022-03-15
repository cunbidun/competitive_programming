# TopCoder setup

## Java applet Topcoder

1. Make sure Java 8 is installed.
`yay -S jre8-openjdk-headless  jre8-openjdk  jdk8-openjdk  openjdk8-doc  openjdk8-src`

2. Disable security by deleting "MD5" from the line that starts with
"jdk.jar.disabledAlgorithms" in with the following commands:

```bash
sudo archlinux-java set java-8-openjdk
sudo $EDITOR /usr/lib/jvm/default/jre/lib/security/java.security

Before: jdk.jar.disabledAlgorithms=MD2, MD5, RSA keySize < 1024, \
After:  jdk.jar.disabledAlgorithms=MD2, RSA keySize < 1024, \
```

**Learn more**: [Source](https://codeforces.cc/blog/entry/90503?#comment-789564)

3. The applet can behave badly. We need to set the wmname

- `yay -S wmname`
- `wmname LG3D`

## Installing KawigiEdit

  1. Start the TopCoder Arena applet.
  2. From the Options menu, choose "Editor".
  3. Click on the "Add" button.
  4. For "Name", enter "KawigiEdit".
  5. For "EntryPoint", enter "kawigi.KawigiEdit".
  6. For "ClassPath", hit "Browse" and find the KawigiEdit jar.
  7. click OK.
  8. If you want KawigiEdit to be used as your default editor, check the "Default".
  9. Click "Save".
