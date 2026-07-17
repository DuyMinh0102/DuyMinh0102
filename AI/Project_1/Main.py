import polars as pl
import polars.selectors as cs

df = pl.read_parquet("items.parquet")

clean_df = df.with_columns(
    [
        pl.col("price").cast(pl.Float64),
        pl.when(cs.string() == "Không xác định")
        .then(None)
        .otherwise(cs.string())
        .name.keep(),
    ]
)

print("Null counts: ")
print(clean_df.null_count())

free_items = clean_df.filter(pl.col("price") == 0)
print(f"Number of 0 VND items: {free_items.height}")
