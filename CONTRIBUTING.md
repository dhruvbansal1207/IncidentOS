# Working together

1. `git pull origin main` before you start working.
2. Work on your own branch:
   - Person 1: `git checkout -b p1/<short-task>`
   - Person 2: `git checkout -b p2/<short-task>`
3. Commit small and often. Push your branch, open a Pull Request, let the other person take a quick look, then merge.
4. Never commit `.env`, virtual environments, `node_modules/` or database files.
5. Changing `data/schemas/*.json` or `docs/data_contract.md` breaks the other person's code. Message first.
