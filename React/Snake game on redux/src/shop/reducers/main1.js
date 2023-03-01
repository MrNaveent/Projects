import { combineReducers } from "redux";

import snakeReducer from "./snake";
import gameReducer from "./game";
import foodReducer from "./food1";

export default combineReducers({
  snake: snakeReducer,
  game: gameReducer,
  food: foodReducer
});
