import * as types from "./types";

/**
 * SNAKE ACTIONS
 */

export const changeDirection = direction => ({
  type: types.CHANGE_DIRECTION,
  payload: direction
});

export const changePosition = position => {
  return {
    type: types.CHANGE_POSITION,
    payload: position
  };
};

/**
 * GAME ACTIONS
 */

export const startGame = () => {
  return {
    type: types.GAME_START
  };
};

/**
 * food ACTIONS
 */

export const addfood = (size, number = 1) => {
  const food = [];

  for (let i = 0; i < number; i++) {
    food.push(makefood(size));
  }

  return {
    type: types.food_ADD,
    payload: food
  };
};

function makefood(size) {
  return {
    width: Math.floor(Math.random() * (size - 2)) + 2,
    depth: Math.floor(Math.random() * (size - 2)) + 2
  };
}
