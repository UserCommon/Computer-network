#include <curl/curl.h>
#include <iostream>

#define LOCALADDR "127.0.0.1:8080"
#define GLOBALADDR "https://github.com/UserCommon"

int main() {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, LOCALADDR);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  return 0;
}
