import * as types from "../shop/types";
import { takeEvery, put, select } from "redux-saga/effects";

export default function* watchPosition() {
  yield takeEvery(types.CHANGE_POSITION, handlePositionChange);
}

const getState = state => ({
  foodPositions: state.food.foodPositions,
  snakeQueue: state.snake.snakeQueue,
  snake: state.snake.snake
});

function* handlePositionChange({ payload }) {
  const { foodPositions, snakeQueue, snake } = yield select(getState);

  const gameIsOver = snake.some((segment, index) => {
    return (
      index !== 0 &&
      segment.width === payload.width &&
      segment.depth === payload.depth
    );
  });

  if (gameIsOver) {
    yield put({ type: types.GAME_END });
    return;
  }

  const foodToRemove = foodPositions.findIndex(food => {
    return food.width === payload.width && food.depth === payload.depth;
  });

  if (foodToRemove >= 0) {
    yield put({ type: types.food_COLLECT, payload: foodToRemove });
    yield put({ type: types.SNAKE_QUEUE, payload });
  }

  if (snakeQueue.length >= 1) {
    yield put({ type: types.SNAKE_GROW });
  }
}
