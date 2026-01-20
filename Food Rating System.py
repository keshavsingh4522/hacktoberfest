from typing import List
import heapq

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_to_cuisine = {}  # Maps food to its cuisine
        self.food_to_rating = {}   # Maps food to its current rating
        self.cuisine_to_foods = {} # Maps cuisine to a max-heap of (-rating, food)

        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_to_cuisine[food] = cuisine
            self.food_to_rating[food] = rating
            if cuisine not in self.cuisine_to_foods:
                self.cuisine_to_foods[cuisine] = []
            heapq.heappush(self.cuisine_to_foods[cuisine], (-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine = self.food_to_cuisine[food]
        self.food_to_rating[food] = newRating
        heapq.heappush(self.cuisine_to_foods[cuisine], (-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        while self.cuisine_to_foods[cuisine]:
            rating, food = self.cuisine_to_foods[cuisine][0]
            # Check if the top of the heap is the current rating of the food
            if -rating == self.food_to_rating[food]:
                return food
            # If not, pop it and continue (this handles the case where a food's rating has changed)
            heapq.heappop(self.cuisine_to_foods[cuisine])

# Example usage:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food, newRating)
# param_2 = obj.highestRated(cuisine)
