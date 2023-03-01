const { model, Schema } = require("mongoose")

const BookModel = model(
  "books",
  new Schema({
    name: { type: String, required: true },
    author: { type: String, required: true },
    publisher: { type: String, required: true },
    isbn: { type: String, required: true, unique: true },
    category: { type: String, required: true },
    quantity: { type: Number, required: true },
    borrowedBy: [{ type: Schema.Types.ObjectId, ref: "users" }],
    
  })
)

module.exports = { BookModel }
