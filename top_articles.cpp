/*
 We're implementing a multi-criteria ranking engine for the HackerRank API.
  
  Logic flow:
  1. Filter: Extract the primary name (Title or Story Title). Discard nulls.
  2. Rank: High-volume discussions (comments) take priority. 
  3. Tie-breaking: Use Alphabetically Decreasing (Z-A) order to resolve collisions.



*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Article {
    string name;
    int num_comments;

};

// A Custom Comparator to implement the specific ranking requirements.
bool compareArticles(const Article& a, const Article& b) {
    if(a.num_comments != b.num_comments){
        return a.num_comments > b.num_comments; // Primary sort: High to Low.
      
    }
    return a.name > b.name; // Secondary sort: Alphabetical Z to A.

}

vector<string> topArticles(int limit){
    vector<Article> filtered_articles;

    /*

      Implementation Logic for API Pagination:

      int total_pages = get_total_pages("https://jsonmock.hackerrank.com/api/articles?page=1");
      
      for (int p = 1; p <= total_pages; p++) {
         auto page_data = fetch_api_data(p);
         for (auto& item : page_data) {
             string display_name = item.title != "" ? item.title : item.story_title;
             
             // Filter out articles with no identifying name
             if (!display_name.empty()) {
                 filtered_articles.push_back({display_name, item.num_comments});
                }
            }
        }
     
    */

    // Performing the sort using our custom comparator
    sort(filtered_articles.begin(), filtered_articles.end(), compareArticles);


    // Extraction: Limit output to the requested 'limit'.
    vector<string> result;
    for (int i = 0; i < limit && i < (int)filtered_articles.size(); i++) {
        result.push_back(filtered_articles[i].name);
    }

    return result;


}