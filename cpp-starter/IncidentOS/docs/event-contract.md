# Event contract

Each event has `id`, `timestamp` (ISO-8601 UTC), `service`, `kind`, and `name`. `value` is numeric metric content; `message` carries log/deployment text. Kinds currently map to `metric`, `log`, `trace`, and `deployment`. Optional fields should be treated as empty/zero. Timestamps should include timezone information and use a consistent representation.
