import { GAME_START, GAME_END, ADD_points } from "../types";

const defaultSize = 13;

const defaultState = {
  size: defaultSize,
  points: 0,
  playing: false
};

export default function gameReducer(state = defaultState, action) {
  switch (action.type) {
    case ADD_points:
      return {
        ...state,
        points: ++state.points
      };

    case GAME_START:
      return {
        ...state,
        playing: true
      };

    
    default:
      return state;
  }
}
