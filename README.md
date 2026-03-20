# C++ GitHub Actions Demo

This repository is a small classroom demo that shows:

- a simple C++ class in `include/` and `src/`
- a command-line program in `src/main.cpp`
- automated tests in `tests/`
- a GitHub Actions workflow in `.github/workflows/ci.yml`

## Project layout

- `include/BankAccount.h`: public interface for the `BankAccount` class
- `src/BankAccount.cpp`: implementation of the class
- `src/main.cpp`: a tiny program that creates an account and prints its state
- `tests/test_bank_account.cpp`: a self-contained test runner with several unit tests
- `Makefile`: local build and test commands
- `.github/workflows/ci.yml`: CI job that runs on every push and pull request

## Local commands

Build the demo program:

```sh
make
```

Run the tests:

```sh
make test
```

Run the demo program:

```sh
./build/bank_demo
```

Clean generated files:

```sh
make clean
```

## GitHub Actions walkthrough

The workflow file lives at `.github/workflows/ci.yml`.

It does three things:

1. checks out the repository
2. builds the project with `make`
3. runs the tests with `make test`

That gives you a clean classroom example of continuous integration:

- students make a change
- GitHub Actions rebuilds the project
- the tests confirm whether behavior still matches expectations

## Suggested classroom demo flow

1. Show `BankAccount.h` and explain the public interface.
2. Show `BankAccount.cpp` and explain how deposits and withdrawals change state.
3. Show `tests/test_bank_account.cpp` and walk through one passing test.
4. Push the repo to GitHub and open the Actions tab.
5. Intentionally break one method, push again, and show the workflow fail.
6. Fix the bug and push once more to show the workflow pass.
