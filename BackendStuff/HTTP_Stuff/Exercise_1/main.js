const apiKey = generateKey();
const items = await getItemData();

logItems(items);

async function getItemData() {
  const apiKey = generateKey();
  const response = await fetch(
    "https://api.boot.dev/v1/courses_rest_api/learn-https/issues",
    {
      method: "GET",
      mode: "cors",
      headers: {
        "X-API-Key": apiKey,
        "Content-Type": "application/json",
      },
    },
  );

  return response.json();
}

function generateKey() {
  const characters = "ABCDEF0123456789";
  let result = "";

  for (let i = 0; i < 16; ++i) {
    result += characters.charAt(Math.floor(Math.random() * characters.length));
  }

  return result;
}

function logItems(items) {
  for (const item of items) {
    console.log(item.title);
  }
}
