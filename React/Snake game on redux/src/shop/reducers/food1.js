import { food_ADD, food_COLLECT, food_CLEAR } from "../types";

const defaultState = {
  foodPositions: []
};

export default function foodReducer(state = defaultState, action) {
  switch (action.type) {
    case food_ADD:
      return {
        ...state,
        foodPositions: [...action.payload, ...state.foodPositions]
      };

    case food_COLLECT:
      const newfood = [...state.foodPositions].filter(
        (_, index) => index !== action.payload
      );

      return {
        ...state,
        foodPositions: newfood
      };

    case food_CLEAR:
      return defaultState;

    default:
      return state;
  }
}
