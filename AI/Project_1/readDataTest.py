import polars as pl

pl.Config.set_tbl_cols(-1)

df = pl.scan_parquet("items.parquet").collect()

raw_preview = df.head(100)

print("Schema: ")
print(df.collect_schema)


print("First 10 rows: ")
print(raw_preview)

print("Null counts: ")
print(df.null_count())

print("Dupe check: ")
duplicate_items = df.filter(pl.col("item_id").is_duplicated())
print(f"Number of duplicated items: {duplicate_items.height}")

print("Distribution: ")
print(
    df.with_columns(pl.col("price").cast(pl.Float64))
    .select(["price", "sale_status"])
    .describe()
)

print("Category and  brand uniqueness")
print("Unique brands: ", df.select(pl.col("brand").n_unique()).item())
print("Unique sizes: ", df.select(pl.col("size").n_unique()).item())

print("Sale status")
print(df["sale_status"].value_counts())
