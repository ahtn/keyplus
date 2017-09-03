aes-min
=======

Minimal AES-128 ([Wikipedia][1]) encryption.

This aims to be suitable for small embedded systems with limited RAM and ROM.

It includes optional on-the-fly key schedule calculation, for minimal RAM usage if required in a very RAM-constrained application. For systems with sufficient RAM, there is also encryption and decryption with a pre-calculated key schedule.

Normally the S-box implementation is by a simple 256-byte table look-up. An optional smaller S-box implementation is included for a *very* ROM-constrained application, where a 256-byte look-up table might be too big. This would only be expected to be necessary for especially tiny target applications, e.g. an automotive keyless entry remote.

Testing
-------

Test programs are included, which test the S-box implementation and encrypt and decrypt operations.

Encryption and decryption are tested against some files in the official [test vectors][2]. Specifically, the ECB mode test files were used, for AES-128. These files:

* `ECBGFSbox128.rsp`
* `ECBKeySbox128.rsp`
* `ECBVarKey128.rsp`
* `ECBVarTxt128.rsp`

The test vectors were parsed and converted to C data structures using a Python program.

When using autotools, run the tests via:

    make check

License
-------

This code is released under the MIT license. See [`LICENSE.txt`][3] for details.


[1]: http://en.wikipedia.org/wiki/Advanced_Encryption_Standard
[2]: http://csrc.nist.gov/groups/STM/cavp/documents/aes/KAT_AES.zip
[3]: LICENSE.txt
