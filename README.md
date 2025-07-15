# csvpack

CSV table parser library with dialect profiles, row filters, column transforms,
statistics helpers, UTF-8 encoding, and pivot utilities.

Install with `make && make test`.

## Build

```bash
make
make test
```

WSL builds with AddressSanitizer:

```bash
bash build/wsl_build.sh
```

## Features

- RFC4180-style CSV parsing with quoted fields and escape sequences
- `@chunk` embedded documents and `${column}` alias expansion
- Table merge overlays and diff serialization
- Dialect registry, row filtering, column transforms, histogram stats, pivot tables
