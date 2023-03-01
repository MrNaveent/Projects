import { useState, useEffect } from "react"
import { Link as RouterLink } from "react-router-dom"
import {
    Button,
    Paper,
    Table,
    TableBody,
    TableCell,
    TableContainer,
    TableHead,
    TableRow,
    Modal,
    Card,
    CardContent,
    CardActions,
    Typography,
    TablePagination,
} from "@mui/material"
import { BackendApi } from "../../client/backend-api"
import { useUser } from "../../context/user-context"
import classes from "./styles.module.css"

export const BooksList = () => {

    const [books, setBooks] = useState([]);
    const [borrowedBook, setBorrowedBook] = useState([])
    const [page, setPage] = useState(0)
    const [rowsPerPage, setRowsPerPage] = useState(4)
    const [activeBookIsbn, setActiveBookIsbn] = useState("")
    const [openModal, setOpenModal] = useState(false)
    const { islibrarian, user } = useUser()


    const fetchBooks = async () => {
        const { books } = await BackendApi.book.getAllBooks()
        setBooks(books)
    }

    const fetchUserBook = async () => {
        const { books } = await BackendApi.user.getBorrowBook()
        setBorrowedBook(books)
    }

    const deleteBook = () => {
        if (activeBookIsbn && books.length) {
            BackendApi.book.deleteBook(activeBookIsbn).then(({ success }) => {
                fetchBooks().catch(console.error)
                setOpenModal(false)
                setActiveBookIsbn("")
            })
        }
    }

    useEffect(() => {
        fetchBooks().catch(console.error)
        fetchUserBook().catch(console.error)
    }, [user])

    return (
        <>
            <div className={`${classes.pageHeader} ${classes.mb2}`}>
                <Typography variant="h3">Books List</Typography>
                {islibrarian && (
                    <Button variant="contained" color="primary" component={RouterLink} to="/librarian/books/add">
                        Add Book
                    </Button>
                )}
            </div>
            {books.length > 0 ? (
                <>
                    <div className={classes.tableContainer}>
                        <TableContainer component={Paper}>
                            <Table stickyHeader>
                                <TableHead>
                                    <TableRow>
                                        <TableCell>Book Name</TableCell>
                                        <TableCell align="right">ID</TableCell>
                                        <TableCell align="right">Author</TableCell>
                                        <TableCell align="right">Publisher</TableCell>
                                        <TableCell align="right">Quantity</TableCell>
                                        <TableCell align="right">Available</TableCell>
                                        <TableCell>Action</TableCell>
                                    </TableRow>
                                </TableHead>
                                <TableBody>
                                    {(rowsPerPage > 0
                                        ? books.slice(page * rowsPerPage, page * rowsPerPage + rowsPerPage)
                                        : books
                                    ).map((book) => (
                                        <TableRow key={book.isbn}>
                                            <TableCell component="th" scope="row">
                                                {book.name}
                                            </TableCell>
                                            <TableCell align="right">{book.isbn}</TableCell>
                                            <TableCell align="right">{book.author}</TableCell>
                                            <TableCell align="right">{book.publisher}</TableCell>
                                            <TableCell align="right">{book.quantity}</TableCell>
                                            <TableCell align="right">{book.availableQuantity}</TableCell>
                                            <TableCell>
                                                <div className={classes.actionsContainer}>
                                                    <Button
                                                        variant="contained"
                                                        component={RouterLink}
                                                        size="small"
                                                        to={`/books/${book.isbn}`}
                                                    >
                                                        View Book
                                                    </Button>
                                                    {islibrarian && (
                                                        <>
                                                            <Button
                                                                variant="contained"
                                                                color="primary"
                                                                component={RouterLink}
                                                                size="small"
                                                                to={`/librarian/books/${book.isbn}/edit`}
                                                            >
                                                                Edit Book
                                                            </Button>
                                                            <Button
                                                                variant="contained"
                                                                color="secondary"
                                                                size="small"
                                                                onClick={(e) => {
                                                                    setActiveBookIsbn(book.isbn)
                                                                    setOpenModal(true)
                                                                }}
                                                            >
                                                                Delete Book
                                                            </Button>
                                                        </>
                                                    )}
                                                </div>
                                            </TableCell>
                                        </TableRow>
                                    ))}
                                </TableBody>
                            </Table>
                        
                        <TablePagination
                            onRowsPerPageChange={(e) => {
                                setRowsPerPage(parseInt(e.target.value, 4))
                                setPage(0)
                            }}
                            component="div"
                            count={books.length}
                            rowsPerPage={rowsPerPage}
                            page={page}
                            onPageChange={(e, newPage) => setPage(newPage)}
                        />
                        </TableContainer>
                        <Modal open={openModal} onClose={(e) => setOpenModal(false)}>
                            <Card className={classes.conf_modal}>
                                <CardContent>
                                    <h2>Are you sure?</h2>
                                </CardContent>
                                <CardActions className={classes.conf_modal_actions}>
                                    <Button variant="contained" onClick={() => setOpenModal(false)}>
                                        Cancel
                                    </Button>
                                    <Button variant="contained" color="secondary" onClick={deleteBook}>
                                        Delete Book
                                    </Button>
                                </CardActions>
                            </Card>
                        </Modal>
                    </div>
                </>
            ) : (
                <Typography variant="h5">No books found!</Typography>
            )}

            {
                user && !islibrarian && (
                    <>
                        <div className={`${classes.pageHeader} ${classes.mb2}`}>
                            <Typography variant="h3">Borrowed Books</Typography>
                        </div>
                        {borrowedBook.length > 0 ? (
                            <>
                                <div className={classes.tableContainer}>
                                    <TableContainer component={Paper}>
                                        <Table stickyHeader>
                                            <TableHead>
                                                <TableRow>
                                                    <TableCell> Book Name</TableCell>
                                                    <TableCell align="right">ID</TableCell>
                                                    <TableCell align="right">Author</TableCell>
                                                    <TableCell align="right">Publisher</TableCell>
                                                    <TableCell></TableCell>
                                                </TableRow>
                                            </TableHead>
                                            <TableBody>
                                                {borrowedBook.map((book) => (
                                                    <TableRow key={book.isbn}>
                                                        <TableCell component="th" scope="row">
                                                            {book.name}
                                                        </TableCell>
                                                        <TableCell align="right">{book.isbn}</TableCell>
                                                        <TableCell align="right">{book.author}</TableCell>
                                                        <TableCell align="right">{book.publisher}</TableCell>
                                                        <TableCell>
                                                            <div className={classes.actionsContainer}>
                                                                <Button
                                                                    variant="contained"
                                                                    component={RouterLink}
                                                                    size="small"
                                                                    to={`/books/${book.isbn}`}
                                                                >
                                                                    View
                                                                </Button>
                                                            </div>
                                                        </TableCell>
                                                    </TableRow>
                                                ))}
                                            </TableBody>
                                        </Table>
                                    </TableContainer>
                                </div>
                            </>
                        ) : (
                            <Typography variant="h5">No books issued!</Typography>
                        )}
                    </>
                )
            }
        </>
    )
}