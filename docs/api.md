# csvpack API

Public symbols use the `csvpack_` prefix; errors use `CSVPACK_*`.

## Parse

- `csvpack_options_init`
- `csvpack_parse_memory` / `csvpack_parse_memory_with_chunks`
- `csvpack_parse_file`
- `csvpack_table_destroy`

## Access

- `csvpack_table_row`, `csvpack_cell_at`, `csvpack_cell_by_column`
- `csvpack_get_int`

## Transform

- `csvpack_serialize_table`, `csvpack_serialize_row`
- `csvpack_merge_tables`, `csvpack_apply_overlay`
- `csvpack_expand_aliases`
- `csvpack_diff_tables`
- `csvpack_validate_table`
