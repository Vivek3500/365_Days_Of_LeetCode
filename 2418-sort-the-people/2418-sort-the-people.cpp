class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int number_of_people = names.size();

        // Create a map to store height-name pairs
        unordered_map<int, string> height_to_name_map;

        // Populate the map with height as key and name as value
        for (int i = 0; i < number_of_people; i++) {
            height_to_name_map[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());

        vector<string> sorted_names(number_of_people);

        // Populate sorted_names vector in descending order of height
        for (int i = number_of_people - 1; i >= 0; i--) {
            sorted_names[number_of_people - i - 1] =
                height_to_name_map[heights[i]];
        }

        return sorted_names;
    }
};