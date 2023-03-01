import { Navigate } from "react-router-dom"
import { useUser } from "../../context/user-context"

export const WithLibrarianProtector = ({ children }) => {
    const { islibrarian } = useUser()
    if (islibrarian) {
        return children
    }
    return <Navigate to="/" replace />
}
