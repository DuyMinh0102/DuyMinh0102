import polars as pl

lazy_df = pl.scan_parquet("transaction_full_2025.parquet")

print("Schema: ")
print(lazy_df.schema)


preprocess_lazy_df = (
    lazy_df.with_columns(pl.col("date_column").cast(pl.Date))
    .with_columns(pl.col("income_column").fill_null(0))
    .filter(pl.col("income_column") >= 0)
    .sort("date_column")
)

print(preprocess_lazy_df.head(10).collect())
