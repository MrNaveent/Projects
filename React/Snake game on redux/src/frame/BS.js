import React from "react";
import { connect } from "react-redux";

function BoardSquare({
  isBorder,
  columnIndex,
  rowIndex,
  snake,
  foodPositions
}) {
  const styles = {
    width: "50px",
    height: "50px",
    backgroundColor: setSquareColor(
      isBorder,
      rowIndex,
      columnIndex,
      snake,
      foodPositions
    )
  };

  if (
    
    styles.backgroundColor === "black"
  ) {
    styles.border = "2px solid grey";
    styles.boxSizing = "border-box";
  }

  return <div style={styles} id={`${columnIndex}x${rowIndex}`} />;
}

const mapStateToProps = state => {
  return {
    snake: state.snake.snake,
    foodPositions: state.food.foodPositions
  };
};

export default connect(mapStateToProps)(BoardSquare);

function setSquareColor(
  isBorder,
  rowIndex,
  columnIndex,
  snake,
  foodPositions
) {
  for (let i = 0; i < snake.length; i++) {
    let snakePosition = snake[i];

    if (
      rowIndex === snakePosition.depth &&
      columnIndex === snakePosition.width
    ) {
      return "green";
    }
  }

  for (let i = 0; i < foodPositions.length; i++) {
    let food = foodPositions[i];

    if (rowIndex === food.depth && columnIndex === food.width) {
      return "red";
    }
  }

  if (isBorder) {
    return "blue";
  }

  return "black";
}
