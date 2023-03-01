import React from "react";
import { connect } from "react-redux";

import BR from "./BR";
import SM from "./SM";
import { changePosition, changeDirection, startGame } from "../shop/actions";

function GameBoard({
  snake,
  size,
  points,
  playing,
  changeDirection,
  changePosition,
  direction,
  startGame
}) {
  SM(
    snake,
    size,
    playing,
    changePosition,
    changeDirection,
    direction
  );

  let keysBound;

  const handleKeyboardEvents = e => {
    const keyboardActions = {
      ArrowUp: "UP",
      ArrowDown: "DOWN",
      ArrowLeft: "LEFT",
      ArrowRight: "RIGHT"
    };

    if (Object.keys(keyboardActions).includes(e.key)) {
      changeDirection(keyboardActions[e.key]);
    }
  };

  if (playing) {
    window.addEventListener("keyup", handleKeyboardEvents);
    keysBound = true;
  }

  if (!playing && keysBound) {
    window.removeEventListener("keyup", handleKeyboardEvents);
  }

  return (
    <div
      style={{
        margin: "0 25vw",
        display: "flex",
        flexDirection: "column"
      }}
    >
      <BR />
      {!playing && (
        <button
          style={{
            backgroundColor: "pink",
            color: "black",
            padding: "0.2rem 2rem",
            alignSelf: "flex-start",
            marginTop: "3rem"
          }}
          onClick={startGame}
        >
          Let's Begin
        </button>
      )}
      <p>POINTS: {points}</p>
      
      
    </div>
  );
}

const mapStateToProps = state => {
  return {
    snake: state.snake.snake,
    size: state.game.size,
    points: state.game.points,
    playing: state.game.playing,
    direction: state.snake.direction
  };
};

export default connect(
  mapStateToProps,
  {
    changePosition: position => changePosition(position),
    changeDirection: direction => changeDirection(direction),
    startGame
  }
)(GameBoard);
